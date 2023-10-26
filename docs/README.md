# EnumMatcher
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/YourUsername/EnumMatcher/Build%20and%20Test%20Unreal%20Engine%20Project)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/YourUsername/EnumMatcher)


# EnumMatcher for Unreal Engine

Welcome to the EnumMatcher documentation! This utility is designed to interpret commands related to key identification in an Unreal Engine project. It recognizes various key commands and numeric hue values, determining the closest predefined key identification option based on the input.

## Overview

The main utility is encapsulated in a class named `UEnumMatcher`. This class provides the following functionalities:

1. **Identify Background Lighting Option**: Given a command (string), it returns the closest matching key identification option (enum value).
2. **Validate Command Identification**: Runs a series of tests to ensure the command identification logic works correctly.

## Key Components

### EBackgroundLighting Enum

This is an enumeration that lists all possible key identification colors and a special 'Hue' value. Each color might have variations (e.g., Orange, Orange2, Orange3).

### UEnumMatcher Class

#### Public Functions:

- `IdentifyLightingOption`: Takes in a command and an output parameter for hue value. Returns the matching key identification option.
- `ValidateCommandIdentification`: Validates the command identification logic using tests.

#### Private Functions:

- `FindNearestPredefinedColor`: Finds the closest predefined color based on the given command.
- `ExtractHueValueIfValid`: Checks if the command corresponds to a valid hue and extracts its value.
- `CalculateStringDifference`: Calculates the Levenshtein distance between two strings to assess similarity.

## How to Use

1. **Identify Lighting Option**:
   ```cpp
   int32 hueValue;
   EBackgroundLighting option = MyUtilityInstance->IdentifyLightingOption("Lightblu", hueValue);
   ```

2. **Run Tests**:
   ```cpp
   MyUtilityInstance->ValidateCommandIdentification();
   ```

## Important Notes

- The utility uses the Levenshtein distance algorithm to find the closest match among predefined colors. This algorithm calculates the minimum number of single-character edits required to change one string into another.
- Hue values are numeric and should be in the range 0-359.

## Getting Help

If you encounter any issues or have questions about the utility, don't hesitate to ask your team lead or refer to the inline documentation in the code.

---

Best wishes, and happy coding!


### Changelog

- Refactored code to be more generic (replacing 'color' with 'key').
- Improved code readability and added more comments.

## Setup
To set up the project, follow these steps:
1. Step 1
2. Step 2

## Contribution Guidelines
To contribute to this project:
1. Fork the repository.
2. Create your feature branch.
3. Commit your changes.
4. Push to the feature branch.
5. Create a new Pull Request.

## Dependencies
This utility relies on the Unreal Engine standard library.

## Exception Handling
Robust exception handling is yet to be implemented. Placeholder comments have been added in the code.

