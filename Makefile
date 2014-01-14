PREFIX := /usr/lib/ssl/fips-2.0

.PHONY: clean install

clean:

install:
	install --directory --mode=0755 $(DESTDIR)$(PREFIX)/bin
	install --mode=0755 output/bin/fipsld $(DESTDIR)$(PREFIX)/bin/fipsld
	install --mode=0755 output/bin/fips_standalone_sha1 $(DESTDIR)$(PREFIX)/bin/fips_standalone_sha1
	install --directory --mode=0755 $(DESTDIR)$(PREFIX)/include
	install --directory --mode=0755 $(DESTDIR)$(PREFIX)/include/openssl
	install --mode=0644 output/include/openssl/fips.h $(DESTDIR)$(PREFIX)/include/openssl/fips.h
	install --mode=0644 output/include/openssl/fipssyms.h $(DESTDIR)$(PREFIX)/include/openssl/fipssyms.h
	install --mode=0644 output/include/openssl/fips_rand.h $(DESTDIR)$(PREFIX)/include/openssl/fips_rand.h
	install --directory --mode=0755 $(DESTDIR)$(PREFIX)/lib
	install --mode=0444 output/lib/fipscanister.o $(DESTDIR)$(PREFIX)/lib/fipscanister.o
	install --mode=0444 output/lib/fipscanister.o.sha1 $(DESTDIR)$(PREFIX)/lib/fipscanister.o.sha1
	install --mode=0444 output/lib/fips_premain.c $(DESTDIR)$(PREFIX)/lib/fips_premain.c
	install --mode=0444 output/lib/fips_premain.c.sha1 $(DESTDIR)$(PREFIX)/lib/fips_premain.c.sha1

