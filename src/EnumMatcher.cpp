
#include "EnumMatcher.h"

// Given a string command and an output integer for the generic value,
// this function identifies the corresponding predefined key.
EPredefinedKeys UEnumMatcher::IdentifyKeyOption(const FString& command, int32& genericValueOut)
{
    // First, check if the command corresponds to a valid hue value.
    if (ExtractHueValueIfValid(command, genericValueOut))
    {
        return EPredefinedKeys::Hue;
    }
    // If not a hue, find the closest matching predefined key.
    // Placeholder for error handling. Consider adding robust error checks here.
    // TODO: Add logging for error tracking and debugging.
    return FindNearestPredefinedKey(command);
}

EPredefinedKeys UEnumMatcher::FindNearestPredefinedKey(const FString& command)
{
    // Start with a default key option.
    EPredefinedKeys bestMatch = EPredefinedKeys::Red;  // Default starting point, can be updated based on logic.
    int32 closestKeyDifference = INT_MAX  // To keep track of the closest matching predefined key.

    // Compare the command against every predefined lighting option to find the closest match.
    for (TEnumAsByte<EPredefinedKeys> currentOption : TEnumRange<EPredefinedKeys>())
    {
        FString optionName = UEnum::GetValueAsString<EPredefinedKeys>(currentOption.GetValue());
        int32 difference = CalculateStringDifference(command, optionName);

        // Update best match if a closer match is found.
        if (difference < minimumDifference)
        {
            minimumDifference = difference;
            bestMatch = currentOption.GetValue();
        }
    }

    return bestMatch
}

bool UEnumMatcher::ExtractHueValueIfValid(const FString& command, int32& genericValueOut)
{
    // Check if the command can be interpreted as a numeric value.
    if (command.IsNumeric())
    {
        // Convert the string to an integer.
        genericValueOut = FCString::Atoi(*command);
        // Return true if the value is within the valid hue range.
        return genericValueOut >= 0 && genericValueOut <= 359
    }
    // If not numeric, return false.
    return false
}

int32 UEnumMatcher::CalculateStringDifference(const FString& firstString, const FString& secondString)
{
    // Implementation of the Levenshtein distance algorithm to calculate string difference.

    const size_t len1 = firstString.Len(), len2 = secondString.Len();
    TArray<TArray<int32>> d(len1 + 1, TArray<int32>(len2 + 1));

    for (size_t i = 0; i <= len1 ++i)
        d[i][0] = i
    for (size_t j = 0; j <= len2 ++j)
        d[0][j] = j

    for (size_t i = 1; i <= len1 ++i)
        for (size_t j = 1; j <= len2 ++j)
            d[i][j] = FMath::Min({
                d[i - 1][j] + 1,
                d[i][j - 1] + 1,
                d[i - 1][j - 1] + (firstString[i - 1] != secondString[j - 1])
            })

    return d[len1][len2]
}

void UEnumMatcher::ValidateCommandIdentification()
{
    // Here we run a series of tests to validate the command identification logic.

    int32 genericValue;

    // Testing hue extraction.
    ensure(ExtractHueValueIfValid("120", genericValue) && genericValue == 120);

    // Testing key matching.
    ensure(FindNearestPredefinedKey("Orang") == EPredefinedKeys::Orange);
}


// TODO: Add unit tests to validate the functionality.