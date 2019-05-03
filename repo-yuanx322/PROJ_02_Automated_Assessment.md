### Assessment for Project Iteration 02 - Automated (Graded By: Dan Orban)

#### Total score: _81.98_ / _85_

Run on December 13, 02:07:08 AM.


#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/_proj_materials" exists.

+ Pass: Setup grading environment.



+  _3_ / _3_ : Pass: Check that directory "PROJ" exists.

+  _2_ / _2_ : Pass: Check that directory "PROJ/src/imagetools" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/color_data.h" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/Makefile" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Setup grading environment.



+  _1_ / _1_ : Pass: Ensuring code follows style guide.



+  _25_ / _25_ : Pass: Check that make compiles.



+  _3_ / _3_ : Pass: Check that file "./build/lib/libimagetools.a" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/flashphoto" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/mia" exists.

+  _3_ / _3_ : Pass: Check that file "./build/test/gtests" exists.


### Instructor Tests

+ Pass: Change into directory "src/tests/inst_tests".

+ Pass: Check that make compiles.



+ Pass: Change into directory "../../..".

+ Pass: Check that file "./build/test/inst_tests" exists.


#### Testing ImageIO Implementation

+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.ImageLoadingAndSaving.




#### Testing MIA Application

+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.StampToolAdded.



+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.DisplayHelpMessage.



+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineCorrect.



+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
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



+  _14.48_ / _15_ : Fail: 96.55% of the tests passed, but the target is 100%.


### Testing Mutants


#### Testing Pen Tool for failure

+ Pass: At least one test failed for Pen Tool


#### Testing Eraser Tool for failure

+ Pass: At least one test failed for Eraser Tool


#### Testing Stamp Tool for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - The stamp tool does not stamp, it slides.


#### Testing Blur Filter for failure

+ Pass: At least one test failed for Blur Filter


#### Testing Edge Detector Filter for failure

+ Pass: At least one test failed for Edge Detector Filter


#### Testing Image IO Implementaiton for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - In Mutant: Image saving and loading is not working.


#### Results

+  _12.5_ / _15_ : Fail: 66.67% of the tests passed, but the target is 80.0%.

#### Total score: _81.98_ / _85_

