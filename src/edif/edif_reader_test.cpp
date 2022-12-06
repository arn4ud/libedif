#include "edif_reader/edif_reader.h"
#include "gtest/gtest.h"

namespace {

TEST(EdifReaderTest, test0) {
    edif::EdifReader reader;
    reader.read("testdata/des.edf");
    reader.read("testdata/fpu.edf");
    reader.read("testdata/or1200.edf");
}

}  // namespace
