
#pragma once

#include "CoreMinimal.h"
#include "EnumMatcher.generated.h"

/**
 * Enum representing possible background lighting options.
 * This includes various key options and a special Hue value.
 */
UENUM(BlueprintType)
enum class EPredefinedKeys : uint8
{
    // Represents various predefined keys that the utility can identify.
    // Each key can correspond to specific actions or states in your application.

    Red,
    // ... other keys
    Hue  // Special case: Represents a generic numeric value.
};

// --- Utility Class Definition ---
};

/**
 * Utility class responsible for handling background lighting commands.
 * This class provides functionality to:
 * - Identify the correct background lighting option based on a command.
 * - Validate the command identification logic through tests.
 */
UCLASS()
class UEnumMatcher : public UObject
{
    GENERATED_BODY()

public:
    /**
     * Analyzes a given command and determines the corresponding background lighting option.
     * @param command - The input command string to analyze.
     * @param hueValueOut - Output parameter to store the hue value if the command represents a hue.
     * @return - The identified background lighting option (key or hue).
     */
    EPredefinedKeys IdentifyKeyOption(const FString& command, int32& hueValueOut);

    /**
     * Runs a series of tests to validate the command identification logic.
     * This function ensures that the command parsing and matching logic is working correctly.
     */
    void ValidateCommandIdentification();

private:
    /**
     * Finds and returns the closest matching predefined key based on the given command.
     * This function uses string matching algorithms to find the best match.
     * @param command - The input command string to match.
     * @return - The closest matching predefined key.
     */
    EPredefinedKeys FindNearestPredefinedKey(const FString& command);

    /**
     * Checks if the provided command corresponds to a valid hue value and extracts it.
     * @param command - The input command string to check and extract hue from.
     * @param hueValueOut - Output parameter to store the extracted hue value.
     * @return - True if the command represents a valid hue, false otherwise.
     */
    bool ExtractHueValueIfValid(const FString& command, int32& hueValueOut);

    /**
     * Calculates the Levenshtein distance (or string edit distance) between two strings.
     * This metric indicates the minimum number of single-character edits needed to change one string into the other.
     * @param firstString - The first input string.
     * @param secondString - The second input string.
     * @return - The calculated Levenshtein distance between the two strings.
     */
    int32 CalculateStringDifference(const FString& firstString, const FString& secondString);
};
