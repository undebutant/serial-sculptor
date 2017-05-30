#include <SFML/Graphics.hpp>

#include "gtest/gtest.h"

#include "SculptorTest.cpp"
#include "CloudEasyTest.cpp"


// Tests for the Sculptor class

TEST_F(SculptorTest, initialize_sculptor) {
	EXPECT_EQ(sculptorToTest.getHealth(), 100);
}

TEST_F(SculptorTest, managing_health) {
	sculptorToTest.setHealth(80);
	EXPECT_EQ(sculptorToTest.getHealth(), 80);

	sculptorToTest.incrHealth(10);
	EXPECT_EQ(sculptorToTest.getHealth(), 90);

	sculptorToTest.decrHealth(30);
	EXPECT_EQ(sculptorToTest.getHealth(), 60);
}

TEST_F(SculptorTest, over_providing_health) {
	sculptorToTest.incrHealth(50);
	EXPECT_EQ(sculptorToTest.getHealth(), 100);
}

TEST_F(SculptorTest, over_decreasing_health) {
	sculptorToTest.decrHealth(130);
	EXPECT_EQ(sculptorToTest.getHealth(), 0);
}

TEST_F(SculptorTest, test_if_game_over) {
	EXPECT_EQ(sculptorToTest.isGameOver(), 0);

	sculptorToTest.decrHealth(100);
	EXPECT_EQ(sculptorToTest.isGameOver(), 1);
}


// Tests for the CloudEasy class

TEST_F(CloudEasyTest, initialize) {
	EXPECT_EQ(CloudEasyToTest.getAlterKeyListSize(), 3);
	EXPECT_EQ(CloudEasyToTest.getColor(), sf::Color(0, 255, 0));
	EXPECT_EQ(CloudEasyToTest.getCurrentKeyIndice(), 0);
	EXPECT_EQ(CloudEasyToTest.isDone(), 0);
}

TEST_F(CloudEasyTest, add_new_key) {
	CloudEasyToTest.addKey(CloudEasyToTest.getAlterKeyList()[0]);

	EXPECT_EQ(CloudEasyToTest.getAlterKeyListSize(), 4);
	EXPECT_EQ(CloudEasyToTest.getCurrentKeyIndice(), 0);
	EXPECT_EQ(CloudEasyToTest.isDone(), 0);
}

TEST_F(CloudEasyTest, right_key_list_entered) {
	EXPECT_EQ(CloudEasyToTest.tryKeyInput(CloudEasyToTest.getAlterKeyList()[0]), 1);
	EXPECT_EQ(CloudEasyToTest.tryKeyInput(CloudEasyToTest.getAlterKeyList()[1]), 1);
	EXPECT_EQ(CloudEasyToTest.tryKeyInput(CloudEasyToTest.getAlterKeyList()[2]), 1);

	EXPECT_EQ(CloudEasyToTest.isDone(), 1);
}

TEST_F(CloudEasyTest, wrong_key_list_entered) {
	EXPECT_EQ(CloudEasyToTest.tryKeyInput(CloudEasyToTest.getAlterKeyList()[0]), 1);
	EXPECT_EQ(CloudEasyToTest.tryKeyInput(CloudEasyToTest.getAlterKeyList()[2]), 0);
	EXPECT_EQ(CloudEasyToTest.tryKeyInput(CloudEasyToTest.getAlterKeyList()[1]), 1);

	EXPECT_EQ(CloudEasyToTest.isDone(), 0);
}

TEST_F(CloudEasyTest, change_cloud_size) {
	CloudEasyToTest.setSize(10.f, -20.4);

	EXPECT_EQ(CloudEasyToTest.getSize().x, 10.f);
	EXPECT_EQ(CloudEasyToTest.getSize().y, (float) -20.4);
}

TEST_F(CloudEasyTest, change_cloud_position) {
	CloudEasyToTest.setPosition(7.2, -20.f);

	EXPECT_EQ(CloudEasyToTest.getPosition().x, (float) 7.2);
	EXPECT_EQ(CloudEasyToTest.getPosition().y, -20.f);
}

TEST_F(CloudEasyTest, change_cloud_color) {
	CloudEasyToTest.setColor(sf::Color(147, 25, 42));

	EXPECT_EQ(CloudEasyToTest.getColor(), sf::Color(147, 25, 42));
}
