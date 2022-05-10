#include <deque>
#include <iostream>
#include <stdexcept>

#if !defined(ONLINE_JUDGE)
#   include <gtest/gtest.h>
#endif

//===================================================================
// train-reorganizer.h
class TrainReorganizer
{
// constructions
public:
    explicit TrainReorganizer(size_t coach_count);
private:
    TrainReorganizer() = delete;

// methods
public:
    void marshal_coach_continuing(size_t coach_number);

private:
    void move_one_coach_to_station();

// data
private:
    std::deque<size_t> coaches_before_entering_station_;
    std::deque<size_t> coaches_in_station_;
};

//===================================================================
// train-reorganizer.cpp
TrainReorganizer::TrainReorganizer(size_t coach_count)
{
    for (size_t i = 1; i <= coach_count; ++i)
    {
        coaches_before_entering_station_.push_back(i);
    }
}

void TrainReorganizer::marshal_coach_continuing(size_t coach_number)
{
    while (1)
    {
        if (!coaches_in_station_.empty() && coaches_in_station_.back() == coach_number)
        {
            coaches_in_station_.pop_back();
            break;
        }
        else if (!coaches_before_entering_station_.empty())
        {
            move_one_coach_to_station();
            continue;
        }

        throw std::runtime_error("marshal_coach_continuing:" + std::to_string(coach_number));
    }
}

void TrainReorganizer::move_one_coach_to_station()
{
    coaches_in_station_.push_back(coaches_before_entering_station_.front());
    coaches_before_entering_station_.pop_front();
}

//===================================================================
size_t read_coach_count(std::istream & is)
{
    int result{0};
    is >> result;
    return result;
}

std::deque<size_t> read_required_order_of_coaches(std::istream & is, size_t coach_count)
{
    size_t coach_number(0);
    is >> coach_number;
    if (coach_number <= 0)
    {
        return std::deque<size_t>(); // end of block
    }

    std::deque<size_t> result;
    result.push_back(coach_number);
    for (size_t i = 1; i < coach_count; ++i)
    {
        is >> coach_number;
        result.push_back(coach_number);
    }
    return result;
}

void solve_uva_problem(std::istream & is, std::ostream & os)
{
    while (1)
    {
        size_t coach_count = read_coach_count(is);
        if (coach_count <= 0)
        {
            break; // end of test
        }

        while (1)
        {
            auto coaches_in_required_order = read_required_order_of_coaches(is, coach_count);
            if (coaches_in_required_order.empty())
            {
                os << std::endl;
                break; // end of block
            }

            TrainReorganizer reorganizer(coach_count);
            try
            {
                while (!coaches_in_required_order.empty())
                {
                    size_t next_coach_number = coaches_in_required_order.front();
                    coaches_in_required_order.pop_front();
                    reorganizer.marshal_coach_continuing(next_coach_number);
                }

                os << "Yes" << std::endl;
            }
            catch(const std::exception & e)
            {
                os << "No" << std::endl;
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
TEST(AddAll, sample_test)
{
    std::istringstream iss(R"--(5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
)--");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ(R"--(Yes
No

Yes

)--", oss.str());
}

TEST(AddAll, uva_online_judge_test)
{
    std::istringstream iss(R"--(5
1 2 3 4 5
5 4 1 2 3
1 4 3 2 5
3 4 2 5 1
3 4 2 1 5
4 3 5 2 1
0
3
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
0
4
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
0
10
5 7 10 9 8 6 4 3 2 1
5 6 4 8 7 3 2 9 1 10
0
0
)--");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ(R"--(Yes
No
Yes
Yes
Yes
Yes

Yes
Yes
Yes
Yes
No
Yes

Yes
Yes
Yes
Yes
No
Yes
Yes
Yes
Yes
Yes
No
Yes
No
No
Yes
Yes
No
Yes
No
No
No
No
No
Yes

Yes
Yes

)--", oss.str());
}
#endif
