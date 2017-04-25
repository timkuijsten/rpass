# rpass

Strong password generator for humans.

Features:
* Both visually and phonetically unambiguous
* No shift or alternate keyboard needed when typing
* Blanks can be inserted at arbitrary places to enhance visual representation


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

Usage:
```sh
$ rpass -h
usage: rpass [bitlen]
```


## Install on macOS
```sh
$ make && sudo make install
```


## Install on OpenBSD
```sh
$ make && doas make install
```


## Key space requirements
The 40 bit default relies on strong storage of the password, i.e. bcrypt(3) with
sufficient rounds. If your password is going to be stored using a weaker
cryptographic construct, you have to use a bigger key space. E.g. say you want
to generate a password you can use for one year and is stored using sha256(1).
Furthermore your adversary has $20,000.00 to spend. According to [8x Nvidia GTX
1080 Hashcat Benchmarks] as of 2016 the adversary can try 230 billion hashes per
second, this makes that you'll need a key space of 64 bit (hashes per second *
3600 * 24 * 365 * 2).

## License

ISC

Copyright (c) 2017 Tim Kuijsten

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


[8x Nvidia GTX 1080 Hashcat Benchmarks]: https://gist.github.com/epixoip/a83d38f412b4737e99bbef804a270c40
