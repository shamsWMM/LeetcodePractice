var hasAllCodes = function(s, k) {
  const total = 2 ** k;
  const seen = new Set();

  for (let i = 0; i <= s.length - k; i++) {
    seen.add(s.substring(i, i + k));
    if (seen.size === total) return true; // early exit
  }

  return false;
};