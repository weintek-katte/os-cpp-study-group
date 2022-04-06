#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

#if !defined(ONLINE_JUDGE)
#   include <gtest/gtest.h>
#endif

int read_number_count(std::istream & is)
{
    int result{0};
    is >> result;
    return result;
}

std::vector<int> read_numbers(std::istream & is, int number_count)
{
    std::vector<int> numbers(number_count);
    for (auto & number : numbers)
    {
        is >> number;
    }
    return numbers;
}

int calculate_minimum_cost(const std::vector<int> & numbers)
{
    std::deque<int> sorted_numbers(numbers.begin(), numbers.end());
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    int cost{0};
    while (sorted_numbers.size() >= 2)
    {
        int sum = sorted_numbers[0] + sorted_numbers[1];
        sorted_numbers.erase(sorted_numbers.begin(), sorted_numbers.begin() + 2);
        sorted_numbers.insert(std::upper_bound(sorted_numbers.begin(), sorted_numbers.end(), sum), sum);
        cost += sum;
    }
    return cost;
}

void solve_uva_problem(std::istream & is, std::ostream & os)
{
    while (1)
    {
        int number_count = read_number_count(is);
        if (number_count <= 0)
        {
            break;
        }

        auto numbers = read_numbers(is, number_count);
        auto minimum_cost = calculate_minimum_cost(numbers);
        os << minimum_cost << std::endl;
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
    std::istringstream iss(R"--(3
1 2 3
4
1 2 3 4
0
)--");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ(R"--(9
19
)--", oss.str());
}

TEST(AddAll, uDebug_RedGreenCode_test)
{
    std::istringstream iss(R"--(17
7 6 60 70 78 44 86 21 7 11 33 44 93 87 68 72 92 
2
56 91 
9
66 85 52 22 44 1 59 88 67 
24
37 61 10 33 17 29 83 74 62 26 93 81 65 35 73 71 45 12 91 44 35 48 69 45 
24
36 32 45 70 26 34 89 53 14 40 66 5 23 29 63 90 98 82 28 76 74 87 3 96 
7
2 89 33 57 79 58 57 
2
52 68 
18
9 14 69 36 21 19 16 22 89 25 55 0 54 51 94 12 7 30 
5
43 81 7 62 17 
3
43 2 40 
20
71 27 23 49 93 61 65 51 35 44 14 14 26 32 1 34 98 3 26 25 
10
33 15 97 40 45 10 29 29 67 97 
3
89 75 76 
20
49 37 18 51 40 11 14 82 10 99 4 59 88 78 65 48 15 4 83 87 
25
16 28 27 16 2 44 10 38 11 29 18 68 17 87 41 89 52 53 74 96 80 62 92 22 84 
25
25 70 82 87 15 46 96 8 82 38 75 6 30 50 98 78 10 92 80 33 94 0 70 45 60 
25
51 38 9 30 53 88 31 44 5 13 22 54 37 82 95 38 37 15 95 21 3 14 52 8 20 
22
88 25 0 98 11 14 75 33 99 42 89 85 6 51 27 83 95 0 63 33 0 12 
6
74 12 15 63 18 95 
17
87 51 50 46 55 45 20 2 38 55 25 52 28 98 47 18 25 
5
30 51 2 42 24 
5
80 64 69 60 86 
9
51 3 50 50 13 44 79 42 49 
16
6 19 99 22 81 58 48 21 27 24 4 2 17 40 88 75 
2
4 8
17
48 48 97 96 71 65 87 95 35 88 0 13 28 4 17 42 79 
8
90 32 20 48 79 36 55 41 
21
42 63 22 87 16 7 97 19 99 3 71 27 87 99 98 23 96 19 7 79 21 
9
8 73 48 87 58 84 58 69 78 
24
32 29 65 81 70 62 80 1 59 31 65 45 61 81 64 9 39 7 45 42 80 22 82 80 
11
14 43 28 14 8 0 13 30 45 3 61 
8
3 87 75 1 3 96 87 66 
10
79 71 77 41 32 53 8 55 35 39 
15
73 12 49 25 64 83 29 70 68 26 75 79 20 36 32 
13
16 30 41 61 79 3 56 79 54 38 30 39 72 
16
1 53 52 93 55 58 33 74 0 82 32 47 81 34 35 56 
4
40 48 55 4 
19
79 0 94 67 20 85 65 87 93 77 42 99 87 34 62 90 3 54 3 
23
95 30 40 33 2 42 77 61 60 45 44 90 37 38 41 99 5 45 27 76 72 90 31 
2
67 53
17
56 76 2 43 77 76 55 95 59 21 7 60 65 16 64 63 72 
12
59 52 14 22 15 16 24 5 94 30 92 27 
23
47 40 84 18 61 43 58 66 46 47 89 4 76 37 68 21 52 5 28 19 84 49 49 
13
45 3 22 79 68 72 40 6 15 48 26 7 36 
7
76 27 38 91 5 76 31 
5
81 1 81 34 87 
21
76 9 19 35 99 53 19 11 10 44 67 17 63 93 59 58 60 86 64 22 84 
7
86 7 65 99 44 66 2 
18
72 2 41 79 96 44 31 37 33 39 66 4 80 5 71 26 18 89 
15
33 24 46 16 53 54 13 90 13 72 86 90 50 27 65 
0
)--");
    std::ostringstream oss;
    solve_uva_problem(iss, oss);

    EXPECT_EQ(R"--(3349
147
1454
5488
5479
992
120
2353
430
127
3185
1418
391
3774
5045
5984
4125
4118
626
2893
324
842
1138
2256
12
3470
1163
4379
1745
5413
782
1068
1584
2796
2113
2983
283
4560
5122
120
3536
1459
4748
1572
884
603
4361
918
3229
2709
)--", oss.str());
}
#endif
