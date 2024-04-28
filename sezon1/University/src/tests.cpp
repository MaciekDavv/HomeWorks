#include <gtest/gtest.h>
#include "DataBase.hpp"
#include "Student.hpp"

struct DataBaseTest : ::testing::Test {
  DataBase db;
};

TEST_F(DataBaseTest, DisplaEmptydb) {
  auto content = db.show();
  auto expected = "";
  EXPECT_EQ(content, expected);
}

TEST_F(DataBaseTest, DisplayNonEmptydb) {

  Student adam {
    "Adam",
    "Kowalski",
    "ul. Dobra 115, 32-700 Bochnia",
    345657,
    "12038045876",
    Gender::Male, 
  };
  db.add(adam);
  // check adding the same person twice

  auto content = db.show();
  auto expected = "Adam Kowalski; ul. Dobra 115, 32-700 Bochnia; 345657; 12038045876; Male";
  EXPECT_EQ(content, expected);
}