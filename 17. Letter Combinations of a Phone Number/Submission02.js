const letterCombinations = function(digits) {
    const keypad = {
        "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
        "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
    };

    // BASE CASE: single digit
    if (digits.length === 1) {
        return [...keypad[digits[0]]]; // ["a", "b", "c"]
    }
    
    // RECURSIVE CASE:
    // 1. Solve for smaller problem (all digits except last)
    const prevCombinations = letterCombinations(digits.slice(0, -1));
    
    // 2. Get letters for the last digit
    const lastLetters = keypad[digits[digits.length - 1]];
    
    // 3. Combine them
    const result = [];
    for (const combo of prevCombinations) {
        for (const letter of lastLetters) {
            result.push(combo + letter);
        }
    }
    
    return result;
};