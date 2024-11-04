function LCS_length(X, Y) {
    let m = X.length;
    let n = Y.length;
    let C = Array(m + 1).fill(null).map(() => Array(n + 1).fill(0));
    let B = Array(m + 1).fill(null).map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (X[i - 1] === Y[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 1;
            } else if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = C[i - 1][j];
                B[i][j] = 2;
            } else {
                C[i][j] = C[i][j - 1];
                B[i][j] = 3;
            }
        }
    }
    return { C, B };
}

function print_LCS(B, X, i, j) {
    if (i === 0 || j === 0) {
        return '';
    }
    if (B[i][j] === 1) {
        return print_LCS(B, X, i - 1, j - 1) + X[i - 1];
    } else if (B[i][j] === 2) {
        return print_LCS(B, X, i - 1, j);
    } else {
        return print_LCS(B, X, i, j - 1);
    }
}

const args = process.argv.slice(2);
if (args.length < 2) {
    console.log("Usage: node LCS.js <string1> <string2>");
    process.exit(1);
}
const X = args[0];
const Y = args[1];
const { C, B } = LCS_length(X, Y);
const lcs = print_LCS(B, X, X.length, Y.length);
console.log("Longest Common Subsequence:", lcs);
