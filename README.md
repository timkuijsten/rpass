# rpass

## Strong password generator for humans

Features:
* Short to type, ideal for use on mobile devices or the command line
* No shift or alternate keyboard needed when typing
* Both visually and phonetically unambiguous
* Blanks can be inserted at arbitrary places to enhance visual representation

## Requirements

Build requirements:
* C89 compiler

Run-time requirements:
* POSIX-compliant system
* support for [arc4random_uniform(3)] (i.e. OpenBSD, FreeBSD, macOS, Linux)

## Install on OpenBSD
```sh
$ make
$ doas make install
```

## Install on macOS, Linux, etc...
```sh
$ make
$ sudo make install
```

## Examples
Random password from a 40 bit key space:
```sh
$ rpass
jikmus xuzjex
```

Random password from a 60 bit key space:
```sh
$ rpass 60
loltuk zahxok takrep
```

## Key space requirements

The default key space of 40 bits relies on the following requirements:
* the adversary has no more than $25,000.00 to spend on brute forcing the
  password (as of 2019 according to [8x Nvidia GTX 1080 Ti Hashcat Benchmarks])
* the password is stored using [bcrypt(3)] with 2^10 rounds
* the password only has to be secure for one year

Additional details about this calculation can be found in the [manual].

## Documentation

All features are documented in the manual: [rpass(1)].

## License

ISC

Copyright (c) 2017, 2019 Tim Kuijsten

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


[8x Nvidia GTX 1080 Ti Hashcat Benchmarks]: https://gist.github.com/epixoip/ace60d09981be09544fdd35005051505
[arc4random_uniform(3)]: https://man.openbsd.org/arc4random_uniform.3
[bcrypt(3)]: https://man.openbsd.org/bcrypt.3
[rpass(1)]: https://netsend.nl/rpass/rpass.1.html
[manual]: https://netsend.nl/rpass/rpass.1.html
