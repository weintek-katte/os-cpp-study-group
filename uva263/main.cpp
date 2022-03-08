#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <boost/lexical_cast.hpp>

#if !defined(ONLINE_JUDGE)
#   include <gtest/gtest.h>
#endif

int64_t arrange_digits_in_ascending_order(const std::string & number)
{
    std::string sorted_number = number;
    std::sort(sorted_number.begin(), sorted_number.end());
    return boost::lexical_cast<int64_t>(sorted_number);
}

int64_t arrange_digits_in_descending_order(const std::string & number)
{
    std::string sorted_number = number;
    std::sort(sorted_number.begin(), sorted_number.end(), std::greater<char>());
    return boost::lexical_cast<int64_t>(sorted_number);
}

size_t number_chain_length(const std::string & original_number, std::ostream & os)
{
    // 1. arranging its digits in descending order
    // 2. arranging its digits in ascending order
    // 3. subtracting the number obtained in (2) from the number obtained (1) to form a new number
    // 4. and repeat these steps unless the new number has already appeared in the chain

    std::set<int64_t> chain;

    std::string number = original_number;
    os << "Original number was " << original_number << std::endl;

    while (1)
    {
        int64_t descending_order_number = arrange_digits_in_descending_order(number);
        int64_t ascending_order_number = arrange_digits_in_ascending_order(number);
        int64_t new_number = descending_order_number - ascending_order_number;
        os << descending_order_number << " - " << ascending_order_number << " = " << new_number << std::endl;

        auto i = chain.find(new_number);
        if (i != chain.end())
        {
            break;
        }
        else
        {
            chain.insert(new_number);
            number = boost::lexical_cast<std::string>(new_number);
        }
    }

    os << "Chain length " << chain.size() + 1 << std::endl << std::endl;
    return chain.size() + 1;
}

void solve_uva_problem(std::istream & is, std::ostream & os)
{
    while (1)
    {
        std::string number;
        std::getline(is, number);

        if (number == "0")
        {
            break;
        }
        else
        {
            number_chain_length(number, os);
        }
    }
}

int main(int argc, char ** argv)
{
#if defined(ONLINE_JUDGE)
    solve_uva_problem(std::cin, std::cout);
#else
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}

#if !defined(ONLINE_JUDGE)
TEST(NumberChainLength, test_123456789)
{
    std::istringstream iss("123456789\n0\n");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ("Original number was 123456789\n"
              "987654321 - 123456789 = 864197532\n"
              "987654321 - 123456789 = 864197532\n"
              "Chain length 2\n"
              "\n", oss.str());
}

TEST(NumberChainLength, test_1234)
{
    std::istringstream iss("1234\n0\n");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ("Original number was 1234\n"
              "4321 - 1234 = 3087\n"
              "8730 - 378 = 8352\n"
              "8532 - 2358 = 6174\n"
              "7641 - 1467 = 6174\n"
              "Chain length 4\n"
              "\n", oss.str());
}

TEST(NumberChainLength, test_444)
{
    std::istringstream iss("444\n0\n");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ("Original number was 444\n"
              "444 - 444 = 0\n"
              "0 - 0 = 0\n"
              "Chain length 2\n"
              "\n", oss.str());
}
#endif
