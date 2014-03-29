#
# Simple CMake wrapper
#

$(VERBOSE).SILENT:

CD=@ cd
MKDIR=@ mkdir -p
MAKE=make
CMAKE=cmake

BUILD_DIR=build
TEST_TIMESTAMP=$(BUILD_DIR)/.test_timestamp

.PHONY : all lib test clean
.DEFAULT_GOAL := all

all: $(BUILD_DIR)
	$(CD) $(BUILD_DIR) && $(CMAKE) -DCELERO_BUILD_TESTS=ON ..
	$(CD) $(BUILD_DIR) && $(MAKE) all

lib: $(BUILD_DIR)
	$(CD) $(BUILD_DIR) && $(CMAKE) ..
	$(CD) $(BUILD_DIR) && $(MAKE) celero && $(MAKE) celero_main

test: $(BUILD_DIR) $(TEST_TIMESTAMP)
	$(CD) $(BUILD_DIR) && $(CMAKE) -DCELERO_BUILD_TESTS=ON ..
	$(CD) $(BUILD_DIR) && $(MAKE) celero-tests-run

clean: $(BUILD_DIR)
	$(CD) $(BUILD_DIR) && $(MAKE) clean

$(TEST_TIMESTAMP): | $(BUILD_DIR)
	echo $$RANDOM$$RANDOM$$RANDOM > $@

$(BUILD_DIR):
	$(MKDIR) $@
