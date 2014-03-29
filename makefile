#
# Simple CMake wrapper
#

$(VERBOSE).SILENT:

CD=@ cd
MKDIR=@  mkdir -p
MAKE=make
CMAKE=cmake

BUILD_DIR=build
TEST_TIMESTAMP=$(BUILD_DIR)/.test_timestamp

.PHONY : all lib build_test test clean
.DEFAULT_GOAL := all

cmake: | $(BUILD_DIR)
	$(CD) $(BUILD_DIR) && $(CMAKE) -DCELERO_BUILD_TESTS=ON ..

all: cmake
	$(CD) $(BUILD_DIR) && $(MAKE) all

lib: cmake
	$(CD) $(BUILD_DIR) && $(MAKE) celero && $(MAKE) celero_main

build_test: cmake
	$(CD) $(BUILD_DIR) && $(MAKE) celero-tests

test: build_test $(TEST_TIMESTAMP)
	$(CD) $(BUILD_DIR) && $(MAKE) celero-tests-run

clean:
	$(CD) $(BUILD_DIR) && $(MAKE) clean

celero%: cmake
	$(CD) $(BUILD_DIR); $(MAKE) $@

$(TEST_TIMESTAMP): | $(BUILD_DIR)
	echo $$RANDOM$$RANDOM$$RANDOM > $@

$(BUILD_DIR):
	$(MKDIR) $@
