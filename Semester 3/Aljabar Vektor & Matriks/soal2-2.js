const u2 = [1, 2, 3];
const v2 = [2, -3, 1];

function scalarMultiply(scalar, vector) {
    return vector.map(component => component * scalar);
}

function subtractVectors(vector1, vector2) {
    return [
        vector1[0] - vector2[0],
        vector1[1] - vector2[1],
        vector1[2] - vector2[2]
    ];
}

// Hitung 7 * v
const sevenV = scalarMultiply(7, v2);

// Hitung u - 7v
const uMinusSevenV = subtractVectors(u2, sevenV);

// Hitung 3 * (u - 7v)
const result = scalarMultiply(3, uMinusSevenV);

console.log("Komponen dari 3(u - 7v):", result);
