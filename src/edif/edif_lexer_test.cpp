/*
 * MIT License
 *
 * Copyright (c) 2022 Arnaud Caron <arn4ud@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "edif_lexer.h"

#include <string>
#include <sstream>

#include "gtest/gtest.h"

namespace edif {
namespace {

class EdifLexerTest : public testing::Test {
protected:
    void check(const std::string& text,
               const std::vector<std::string>& tokens)
    {
        EdifLexer lexer;
        std::istringstream iss(text);
        lexer.switch_streams(&iss, nullptr);

        for (const auto& token : tokens) {
            EdifParser::symbol_type symbol = lexer.get_token();
            EXPECT_EQ(symbol.name(), token);
        }
    }
};

TEST_F(EdifLexerTest, keywords) {
    std::vector<std::string> keywords = {
        "array", "author", "boolean", "cell", "cellref", "comment", "contents",
        "design", "e", "edif", "ediflevel", "edifversion", "external", "false",
        "globalportref", "instance", "instanceref", "integer", "interface",
        "joined", "keywordlevel", "keywordmap", "library", "libraryref",
        "listofnets", "listofports", "member", "name", "net", "netbundle",
        "number", "numberdefinition", "port", "portbundle", "portlist",
        "portref", "program", "property", "rename", "status", "string",
        "technology", "timestamp", "true", "version", "view", "viewref",
        "written",
    };
    for (const auto& keyword : keywords) {
        std::string text = "(" + keyword + " " + keyword + ")";
        check(text, 
                {"(", keyword, "Identifier", ")", "end of file"});
    }
}

TEST_F(EdifLexerTest, celltype) {
    check("(celltype generic)",
          {"(", "celltype", "generic", ")", "end of file"});
    check("(CellType Generic)",
          {"(", "celltype", "generic", ")", "end of file"});
    check("(CELLTYPE GENERIC)",
          {"(", "celltype", "generic", ")", "end of file"});
}

TEST_F(EdifLexerTest, viewtype) {
    check("(viewtype netlist)",
          {"(", "viewtype", "netlist", ")", "end of file"});
    check("(ViewType Netlist)",
          {"(", "viewtype", "netlist", ")", "end of file"});
    check("(VIEWTYPE NETLIST)",
          {"(", "viewtype", "netlist", ")", "end of file"});
}

TEST_F(EdifLexerTest, direction) {
    check("(direction inout)",
          {"(", "direction", "inout", ")", "end of file"});
    check("(Direction InOut)",
          {"(", "direction", "inout", ")", "end of file"});
    check("(DIRECTION INOUT)",
          {"(", "direction", "inout", ")", "end of file"});

    check("(direction input)",
          {"(", "direction", "input", ")", "end of file"});
    check("(Direction Input)",
          {"(", "direction", "input", ")", "end of file"});
    check("(DIRECTION INPUT)",
          {"(", "direction", "input", ")", "end of file"});

    check("(direction output)",
          {"(", "direction", "output", ")", "end of file"});
    check("(Direction Output)",
          {"(", "direction", "output", ")", "end of file"});
    check("(DIRECTION OUTPUT)",
          {"(", "direction", "output", ")", "end of file"});
}

TEST_F(EdifLexerTest, integer) {
}

TEST_F(EdifLexerTest, string) {
}

TEST_F(EdifLexerTest, identifiers) {
}

}  // namespace
}  // namespace edif
