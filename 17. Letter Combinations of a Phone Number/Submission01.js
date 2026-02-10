/**
 * @param {string} digits
 * @return {string[]}
 */
const letterCombinations = function(digits) {
    const keypad = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz"
    };

    let result = [];
    
    // digit #1
    for (ch of keypad[digits[0]]) {
        result.push(ch);
    }

    if (digits.length == 1)
        return result;

    // digit #2
    let count = 0;
    for (ch of keypad[digits[1]]) {
        for (chPrev of keypad[digits[0]]) {
            let st = chPrev + ch;
            result[count++] = st;
        }
    }
    if (digits.length == 2)
        return result;

    // digit #3
    count = 0;
    for (ch of keypad[digits[2]]) {
        for (chPrev of keypad[digits[1]]) {
            for (chPrevPrev of keypad[digits[0]]) {
            let st = chPrevPrev + chPrev + ch;
            result[count++] = st;
            }
        }
    }
    if (digits.length == 3)
        return result;

    // digit #4
    count = 0;
    for (ch of keypad[digits[3]]) {
        for (chPrev of keypad[digits[2]]) {
            for (chPrevPrev of keypad[digits[1]]) {
                for (chPrevPrevPrev of keypad[digits[0]]) {
                let st = chPrevPrevPrev + chPrevPrev + chPrev + ch;
                result[count++] = st;
                }
            }
        }
    }
    if (digits.length == 4)
        return result;
};