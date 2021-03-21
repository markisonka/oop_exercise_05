#include <queue>
#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

#include "Queue.h"

TEST(QueueInterface, TestQueueInterface) {

    Containers::Queue<int> test_queue;
    ASSERT_ANY_THROW(test_queue.Pop());
    for (int i = 1; i <= 10; ++i) {
        test_queue.Push(i);
    }
    vector<int> ok_result {1,2,3,4,5,6,7,8,9,10};
    vector<int> result;
    for (int i : test_queue) {
        result.push_back(i);
    }
    ASSERT_TRUE(result == ok_result);
    for (int i = 0; i < 5; ++i) {
        test_queue.Pop();
    }
    ok_result = {6,7,8,9,10};
    result.clear();
    for (int i : test_queue) {
        result.push_back(i);
    }
    ASSERT_TRUE(result == ok_result);
    while (!test_queue.Empty()) {
        test_queue.Pop();
    }
    ok_result.clear();
    result.clear();
    for (int i : test_queue) {
        result.push_back(i);
    }
    ASSERT_TRUE(result == ok_result);
    ASSERT_ANY_THROW(test_queue.Pop());
}

TEST(QueueIterators, TestQueueIterators) {
    Containers::Queue<int> test_queue;
    for (int i = 1; i <= 10; ++i) {
        test_queue.Push(i);
    }
    auto it = test_queue.begin();
    ASSERT_EQ(*it, test_queue.Top());
    *it = 10;
    ASSERT_EQ(*it, test_queue.Top());
    ASSERT_EQ(*it, 10);
    it++;
    *it = 11;
    test_queue.Pop();
    ASSERT_EQ(test_queue.Top(), *it);
    ASSERT_EQ(test_queue.Top(), 11);
    ASSERT_EQ(test_queue.begin(), it);
    for (int i = 0; i < 9; ++i) {
        it++;
    }
    ASSERT_EQ(test_queue.end(), it);
    ASSERT_ANY_THROW(it++);
}

TEST(QueueInsertErase, TestQueueInsertErase) {
    Containers::Queue<int> test_queue;
    for (int i = 1; i <= 10; ++i) {
        test_queue.Push(i);
    }
    vector<int> result;
    for (int i : test_queue) {
        result.push_back(i);
    }
    vector<int> expected_result = {1,2,3,4,5,6,7,8,9,10};
    ASSERT_TRUE(result == expected_result);
    auto it = test_queue.begin();
    test_queue.Insert(it, 11);
    test_queue.Insert(it, 12);
    it++;
    it++;
    test_queue.Insert(it, 4);
    it++;
    test_queue.Erase(it);
    expected_result = {11,12,1,2,4,3,5,6,7,8,9,10};
    result.clear();

    for (int i : test_queue) {
        result.push_back(i);
    }
    ASSERT_TRUE(result == expected_result);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}