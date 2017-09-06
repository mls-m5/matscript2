//Mattias Larsson Sköld 


#include "unittest.h"
#include "ast.h"


TEST_SUIT_BEGIN

TEST_CASE("basic split") {
    AstUnit unit("hej san");
    unit.split();

    ASSERT_EQ(unit.size(), 2);
}

TEST_CASE("basic group") {
    AstUnit unit("hej + san * 2");

    //assert that it has been grouped the right way
}


TEST_SUIT_END