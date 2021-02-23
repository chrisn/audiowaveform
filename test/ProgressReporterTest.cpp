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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <sstream>

//------------------------------------------------------------------------------

using testing::StrEq;
using testing::Test;

//------------------------------------------------------------------------------

class ProgressReporterTest : public Test
{
    protected:
        virtual void SetUp()
        {
            error.str(std::string());
        }

        virtual void TearDown()
        {
        }

    protected:
        ProgressReporter progress_reporter_;
};

//------------------------------------------------------------------------------

TEST_F(ProgressReporterTest, shouldDisplayZeroPercentWhenFirstCalled)
{
    progress_reporter_.update(0, 100);

    ASSERT_THAT(error.str(), StrEq("\rDone: 0%"));
}

//------------------------------------------------------------------------------
