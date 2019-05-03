### Feedback for Project Iteration 02

Run on December 12, 16:27:15 PM.


#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/_proj_materials" exists.

+ Pass: Setup grading environment.



+ Pass: Check that directory "PROJ" exists.

+ Pass: Check that directory "PROJ/src/imagetools" exists.

+ Pass: Check that file "PROJ/src/imagetools/color_data.h" exists.

+ Pass: Check that file "PROJ/src/imagetools/Makefile" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Setup grading environment.



+ Pass: Ensuring code follows style guide.



+ Pass: Check that make compiles.



+ Pass: Check that file "./build/lib/libimagetools.a" exists.

+ Pass: Check that file "./build/bin/flashphoto" exists.

+ Pass: Check that file "./build/bin/mia" exists.

+ Pass: Check that file "./build/test/gtests" exists.


### Instructor Tests

+ Pass: Change into directory "src/tests/inst_tests".

+ Pass: Check that make compiles.



+ Pass: Change into directory "../../..".

+ Pass: Check that file "./build/test/inst_tests" exists.


#### Testing ImageIO Implementation

+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.ImageLoadingAndSaving.




#### Testing MIA Application

+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.StampToolAdded.



+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.DisplayHelpMessage.



+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineCorrect.



+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineBadInput.




### Run Student Tests

+ Pass: Check that file "./build/test/gtests" exists.

+ Pass: Get all google tests.
    29 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolPenTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolPenTest.HasCorrectMask.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolEraserTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolEraserTest.HasCorrectMask.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolBlurTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolBlurTest.HasCorrectMask.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineParsingTest.ImageEndingError.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineParsingTest.NoInputImageError.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineParsingTest.NoOutputImageError.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineParsingTest.WrongCommandError.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineParsingTest.CommandMissingElementError.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolChalkTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolChalkTest.HasCorrectMask.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.BlurFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.EdgeDetectFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.SharpenFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ThresholdFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.SaturateFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.RedChannelFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.GreenChannelFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.BlueChannelFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.QuantizeFilterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.MotioinBlurFilterTest.



+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.BlurToolTest.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.BlurToolTest
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.BlurToolTest




+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.CalligraphyToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ChalkToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.EraserToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.HighlighterToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.PenToolTest.



+ Fail: 96.55% of the tests passed, but the target is 100%.

