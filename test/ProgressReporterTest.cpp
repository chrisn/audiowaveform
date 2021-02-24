//------------------------------------------------------------------------------
//
// Copyright 2013-2019 BBC Research and Development
//
// Author: Chris Needham
//
// This file is part of Audio Waveform Image Generator.
//
// Audio Waveform Image Generator is free software: you can redistribute it
// and/or modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// Audio Waveform Image Generator is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// Audio Waveform Image Generator.  If not, see <http://www.gnu.org/licenses/>.
//
//------------------------------------------------------------------------------

#include "ProgressReporter.h"
#include "util/Streams.h"

// #include "gmock/gmock.h"

#include <iostream>

//------------------------------------------------------------------------------

// using testing::StrEq;

//------------------------------------------------------------------------------

std::string transform(const std::string& input)
{
    std::string output;

    for (std::size_t i = 0; i < input.size(); i++) {
        if (input[i] == '\r') {
            output += "\\r";
        }
        else {
            output += input[i];
        }
    }

    return output;
}

//------------------------------------------------------------------------------

// TEST(ProgressReporter, shouldDisplayZeroPercentWhenFirstCalled)
bool Test()
{
    ProgressReporter progress_reporter;

    progress_reporter.update(0, 100);

    const char* expected = "\rDone: 0%";
    std::string actual = error.str();

    bool equal = actual == std::string(expected);

    std::cout << "actual: " << transform(actual) << '\n';
    std::cout << "expected: " << transform(expected) << '\n';
    std::cout << "equal: " << equal << '\n';

    const char* test_string = "Test\rTest 2";
    std::ostringstream s;
    s << test_string;
    actual = s.str();

    std::cout << "actual: " << transform(actual) << '\n';
    std::cout << "expected: " << transform(test_string) << '\n';
    std::cout << "equal: " << equal << '\n';


    // ASSERT_THAT(error.str(), StrEq("\rDone: 0%"));
    return equal;
}

int main()
{
    return Test() ? 0 : 1;
}

//------------------------------------------------------------------------------
