#include <iostream>
#include <vector>

#if !defined(ONLINE_JUDGE)
#   include <gtest/gtest.h>
#endif

//===================================================================
class CounterfeitCoinFinder
{
// typedefs
public:
    using CoinIndex = size_t;
    enum class WeightingResult { Even, Up, Down };
    enum class CoinStatus
    {
        Unknown,
        Genuine,
        LikelyLighter, // could be counterfeit
        LikelyHeavier, // could be counterfeit
    };

// constructions
public:
    explicit CounterfeitCoinFinder(size_t coin_count) : coins_(coin_count) {
        // TODO
    }
private:
    CounterfeitCoinFinder() = delete;

// methods
public:
    // specify weighting result
    CounterfeitCoinFinder & weight(const std::vector<CoinIndex> & left_balance_coins,
                                   const std::vector<CoinIndex> & right_balance_coins) const {
        // TODO
        return *const_cast<CounterfeitCoinFinder *>(this);
    }
    void result(WeightingResult weighting_result) {
        // TODO
    }

    // get status of all coins
    std::vector<CoinStatus> const & coins() const { return coins_; }

// data
private:
    std::vector<CoinStatus> coins_;
};

//===================================================================
template <typename number_type>
number_type read_number(std::istream & is)
{
    number_type result{0};
    is >> result;
    return result;
}

std::vector<CounterfeitCoinFinder::CoinIndex> coins_from_string(const std::string & s)
{
    // TODO
    return std::vector<CounterfeitCoinFinder::CoinIndex>();
}

CounterfeitCoinFinder::WeightingResult weighting_result_from_string(const std::string & s)
{
    // TODO
    return static_cast<CounterfeitCoinFinder::WeightingResult>(0);
}

void solve_uva_problem(std::istream & is, std::ostream & os)
{
    static const size_t TotalCoinCount = 12;
    static const size_t InputLinesForEachCase = 3;

    int case_count = read_number<int>(is);
    while (case_count-- > 0)
    {
        CounterfeitCoinFinder ccf(TotalCoinCount);
        for (size_t i = 0; i < InputLinesForEachCase; ++i)
        {
            std::string str_left_balance_coins;
            std::string str_right_balance_coins;
            std::string str_weighting_result;
            is >> str_left_balance_coins >> str_right_balance_coins >> str_weighting_result;

            // specify weighting result
            auto left_balance_coins = coins_from_string(str_left_balance_coins);
            auto right_balance_coins = coins_from_string(str_right_balance_coins);
            auto weighting_result = weighting_result_from_string(str_weighting_result);
            ccf.weight(left_balance_coins, right_balance_coins).result(weighting_result);
        }

        // find the counterfeit coin
        auto coins = ccf.coins();
        for (size_t i = 0; i < coins.size(); ++i)
        {
            auto coin = coins[i];
            if (coin == CounterfeitCoinFinder::CoinStatus::LikelyLighter)
            {
                os << static_cast<char>('A' + i) << " is the counterfeit coin and it is light." << std::endl;
                break;
            }
            else if (coin == CounterfeitCoinFinder::CoinStatus::LikelyHeavier)
            {
                os << static_cast<char>('A' + i) << " is the counterfeit coin and it is heavy." << std::endl;
                break;
            }
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
TEST(CounterfeitCoinFinder, sample_test)
{
    std::istringstream iss(R"--(1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
)--");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ(R"--(K is the counterfeit coin and it is light.
)--", oss.str());
}
#endif
