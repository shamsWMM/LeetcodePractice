var isValid = function(s) {
    const stack = [];
    const corresponds = {
        '}' : '{',
        ')' : '(',
        ']' : '['
    }

    for (const char of s) {
        if (corresponds[char]) {
            const last = stack.pop();
            if (last !== corresponds[char])
                return false;
        }
        else {
            stack.push(char);
        }
    }
    return stack.length === 0;
};