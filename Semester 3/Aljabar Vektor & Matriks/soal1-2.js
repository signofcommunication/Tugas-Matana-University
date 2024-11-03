function addVectors(vector1, vector2) {
    return [
        vector1[0] + vector2[0],
        vector1[1] + vector2[1],
        vector1[2] + vector2[2]
    ];
}

const uPlusV = addVectors(u, v);
const magnitudeUPlusV = magnitude(uPlusV);

console.log("Vektor u + v:", uPlusV);
console.log("Panjang vektor |u + v|:", magnitudeUPlusV);
