#include "ll.h"
#include <forward_list>
#include <gtest/gtest.h>

using namespace CS270;

TEST(SLL, constructor) {
  forward_list<int> intlist;
  forward_list<float> floatlist;
}

TEST(SLL, front_and_push) {
  forward_list<int> list;
  list.push_front(0);
  EXPECT_EQ(0, list.front());
  list.push_front(1);
  EXPECT_EQ(1, list.front());
}

TEST(SLL, pop) {
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  EXPECT_EQ(2, list.front());
  list.pop_front();
  EXPECT_EQ(1, list.front());
  list.pop_front();
  EXPECT_EQ(0, list.front());
}


TEST(SLL, empty) {
  forward_list<int> list;
  EXPECT_EQ(true, list.empty());
  list.push_front(0);
  EXPECT_EQ(false, list.empty());
  list.push_front(1);
  EXPECT_EQ(false, list.empty());
  list.push_front(2);
  EXPECT_EQ(false, list.empty());
  list.pop_front();
  EXPECT_EQ(false, list.empty());
  list.pop_front();
  EXPECT_EQ(false, list.empty());
  list.pop_front();
  EXPECT_EQ(true, list.empty());
}


TEST(SLL, remove) {
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);  // List: 4 -> 3 -> 2 -> 1 -> 0

  // Remove head
  list.remove(4);
  EXPECT_EQ(3, list.front());

  // Remove middle
  list.remove(1);
  EXPECT_EQ(3, list.front());

  // Remove non-existent element
  list.remove(10);
  EXPECT_FALSE(list.empty());

  // Remove tail
  list.remove(0);  // remove last element
  EXPECT_FALSE(list.empty());

  // Remove all elements one by one
  list.remove(3);
  list.remove(2);
  EXPECT_TRUE(list.empty());
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
