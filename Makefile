SHELL = /bin/sh

thisdir = $(shell pwd)

# Generic Rules
# --------------------------------------------------

all: debug-all release-all coverage-all
check: debug-check check-release coverage-check
install: debug-install release-install coverage-install

# End of file

# CMake debug build
# --------------------------------------------------

debug-all: build/debug/Makefile
	$(MAKE) -C build/debug all

debug-check: debug-all
	$(MAKE) -C build/debug test

debug-install: debug-all
	$(MAKE) -C build/debug install

build/debug/Makefile:
	mkdir -p $(@D)
	cd $(@D) && cmake \
	    -DCMAKE_BUILD_TYPE=Debug \
	    -DCMAKE_INSTALL_PREFIX:PATH=$(thisdir)/build/debug ../..

.PHONY: debug-all debug-check debug-install

# CMake release build
# --------------------------------------------------

release-all: build/release/src/Makefile
	$(MAKE) -C build/release/src

check-release: release-all
	$(MAKE) -C build/release/src test

release-install: release-all
	$(MAKE) -C build/release/src install

build/release/src/Makefile:
	mkdir -p $(@D)
	cd $(@D) && cmake \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_INSTALL_PREFIX:PATH=$(thisdir)/build/release ../../..

.PHONY: release-all check-release release-install

# CMake coverage build
# --------------------------------------------------

coverage-all: build/coverage/src/Makefile
	$(MAKE) -C build/coverage/src

coverage-check: coverage-all
	$(MAKE) -C build/coverage/src test

coverage-install: coverage-all
	$(MAKE) -C build/coverage/src install

build/coverage/src/Makefile:
	mkdir -p $(@D)
	cd $(@D) && cmake \
		-DWITH_COVERAGE=YES \
		-DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_INSTALL_PREFIX:PATH=$(thisdir)/build/coverage ../../..

.PHONY: coverage-all coverage-check coverage-install

coverage-check-report: check-coverage
	cd ./build/coverage/src/CMakeFiles/verilogparser.dir/ ; \
	gcov -abcf *.o  ; \
	lcov --directory . -c -o cov.info -t "verilogparser" ; \
	genhtml -o ../../../../coverage-report -t "verilogparser" --num-spaces 4 cov.info
	@echo "Coverage report available in:"
	@echo "./build/coverage-report/index.html"
