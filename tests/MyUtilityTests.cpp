#include "MyUtilityTests.h"
#include "EnumMatcher.h"  // Include the EnumMatcher header

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEnumMatcherTest, "EnumMatcher.BasicTest", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEnumMatcherTest::RunTest(const FString& Parameters)
{
    // Initialize a sample enum and a test string
    ESampleEnum sampleEnum = ESampleEnum::OptionA;
    FString testString = "OptionB";

    // Use EnumMatcher to find the closest enum
    ESampleEnum resultEnum = EnumMatcher::FindNearestEnum(testString, sampleEnum);

    // Validate the result
    TestEqual("EnumMatcher should return OptionB", resultEnum, ESampleEnum::OptionB);

    return true;
}
