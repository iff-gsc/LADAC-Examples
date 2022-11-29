% Minnie_UnitTest implements test functions for the models
% based in the Minnie Quadcopter in Multicopter library
%
%   These functions define test cases with well known results.
%   This unit test should be run every time the file has been modified,
%   to prove that results are still as expected.
%   If any changes has been made to the function this test
%   script can be used to find unintended errors.
%
%   example call: rt = table(runtests('Minnie_UnitTest'))
%
% Literature: 
%   [1] https://blogs.mathworks.com/loren/2013/10/15/function-is-as-functiontests/
%
%   [2] https://de.mathworks.com/help/matlab/matlab_prog/write-function-based-unit-tests-.html
%

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Fabian Guecker
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% Call all subfunction tests in this file
function tests = Minnie_UnitTest
    addPathMinnie;
    tests = functiontests(localfunctions);
end

function Test_Minnie_Loiter_INDI_simple(testCase)

validateModelBuild('init_quadcopter_Minnie_Loiter_INDI_simple');

end

function Test_Minnie_AltHold_INDI_simple(testCase)

validateModelBuild('init_quadcopter_Minnie_AltHold_INDI_simple');

end

function Test_Minnie_Minnie_ArduPilot_SITL(testCase)

validateModelBuild('init_quadcopter_Minnie_ArduPilot_SITL');

end
