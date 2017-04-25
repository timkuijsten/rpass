/**
 * Copyright (c) 2017 Tim Kuijsten
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Dutch three letter "words" that are both visually and phonetically
 * unambiguous.
 */
static const char first[] = "bdfhjklmnprstvwxz"; /* drop c, g, q, y = 4 bpc */
static const char secon[] = "aeiou";             /* vowels, 2.3 bpc */
static const char third[] = "fhjklmnprstxz";     /* drop b, c, d, g, q, v, w, y = 3.7 bpc */

int
main(int argc, char **argv)
{
  int c;
  double bits, fbpc, sbpc, tbpc;

  while ((c = getopt(argc, argv, "h")) != -1)
    switch (c) {
    case 'h':
    case '?':
      fputs("usage: rpass [bitlen]\n", stdout);
      exit(0);
    default:
      fputs("usage: rpass [bitlen]\n", stderr);
      exit(1);
    }
  argc -= optind;
  argv += optind;

  fbpc = log2(sizeof first - 1);
  sbpc = log2(sizeof secon - 1);
  tbpc = log2(sizeof third - 1);

  if (argc)
    bits = strtol(argv[0], NULL, 10);
  else
    bits = 40.0;

  if (bits <= 0) {
    fputs("usage: rpass [bitlen]\n", stderr);
    exit(1);
  }

  /* make three letter words */
  c = 0;
  while (bits > 0) {
    putchar(first[arc4random_uniform(sizeof first - 1)]);
    bits -= fbpc;

    putchar(secon[arc4random_uniform(sizeof secon - 1)]);
    bits -= sbpc;

    putchar(third[arc4random_uniform(sizeof third - 1)]);
    bits -= tbpc;

    if (bits > 0 && c++ % 2)
      putchar(' ');
  }

  putchar('\n');

  return 0;
}
