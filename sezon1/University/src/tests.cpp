#include <gtest/gtest.h>
#include "DataBase.hpp"
#include "Student.hpp"

TEST(CheckStructure, CanAddSdudentToDb_Req1_Req2) {
  Student adam {
    "Adam",
    "Kowalski",
    "ul. Dobra 115, 32-700 Bochnia",
    345657,
    "12038045876",
    Gender::Male, 
  };

  DataBase db;
  EXPECT_TRUE(db.add(adam));
  EXPECT_FALSE(db.add(adam));
}

TEST(Displaydb, DisplaEmptydb) {
  DataBase db;
  auto content = db.show();
  auto expected = "";
  EXPECT_EQ(content, expected);
}

// TEST(Displaydb, DisplayNonEmptydb) {
//   DataBase db;

//   Student adam {
//     "Adam",
//     "Kowalski",
//     "ul. Dobra 115, 32-700 Bochnia",
//     345657,
//     "12038045876",
//     Gender::Male, 
//   };

//   EXPECT_TRUE(db.add(adam));
//   db.display();

// }