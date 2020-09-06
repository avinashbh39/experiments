#include <gtest/gtest.h>
#include "trie.hpp"

class TrieTest : public ::testing::Test {
 protected:
  void SetUp() override {
	m_dict.Insert("boys");
	m_dict.Insert("bird");
	m_dict.Insert("zone");
	m_dict.Insert("rogers");
	m_dict.Insert("zombie");
	m_dict.Insert("rat");
	m_dict.Insert("ratify");
  }

  Util::Trie m_dict ;

};

TEST_F(TrieTest,EmptyString)
{
	EXPECT_TRUE(m_dict.FindWord("") == false);
}

TEST_F(TrieTest,WordPresent)
{
	EXPECT_TRUE(m_dict.FindWord("bird") == true);
	EXPECT_TRUE(m_dict.FindWord("rat") == true);
	EXPECT_TRUE(m_dict.FindWord("ratify") == true);
}

TEST_F(TrieTest,WordNotPresent)
{
	EXPECT_TRUE(m_dict.FindWord("bir") == false);
	EXPECT_TRUE(m_dict.FindWord("ratif") == false);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}