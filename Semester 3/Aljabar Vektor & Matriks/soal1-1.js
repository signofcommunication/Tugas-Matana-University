function magnitude(vector) {
    return Math.sqrt(vector[0] ** 2 + vector[1] ** 2 + vector[2] ** 2);
}

const u = [1, -3, 2];
const v = [1, 1, 0];

const magnitudeU = magnitude(u);
const magnitudeV = magnitude(v);

console.log("Panjang vektor |u|:", magnitudeU);
console.log("Panjang vektor |v|:", magnitudeV);
