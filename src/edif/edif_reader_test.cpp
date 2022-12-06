#include "edif/edif_reader.h"
#include "gtest/gtest.h"

namespace {

TEST(EdifReaderTest, des) {
    edif::EdifReader reader;
    reader.read("testdata/des.edf");
}

TEST(EdifReaderTest, fpu) {
    edif::EdifReader reader;
    reader.read("testdata/fpu.edf");
}

TEST(EdifReaderTest, or1200) {
    edif::EdifReader reader;
    reader.read("testdata/or1200.edf");
}

}  // namespace
