#include "../MaBibliotheque/Cloud.h"
#include "gtest/gtest.h"


class CloudEasyTest : public::testing::Test {
protected:
	// All functions can be removed if its body is empty
	Cloud CloudEasyToTest = Cloud();

	CloudEasyTest() {
		// You can do set-up work for each test here
	}

	virtual ~CloudEasyTest() {
		// You can do clean-up work that doesn't throw exceptions here
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test)
		CloudEasyToTest = Cloud();
		CloudEasyToTest.setColor(sf::Color(0, 255, 0));

		CloudEasyToTest.addKey('A');
		CloudEasyToTest.addKey('B');
		CloudEasyToTest.addKey('C');
		CloudEasyToTest.addKey('D');

	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor)
	}


	// Objects declared here can be used by all tests in the test case for Foo

	
	
};
