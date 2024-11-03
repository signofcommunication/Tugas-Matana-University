function dotProduct(vector1, vector2) {
    return vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2];
}

function angleBetweenVectors(vector1, vector2) {
    const dotProd = dotProduct(vector1, vector2);
    const magnitude1 = magnitude(vector1);
    const magnitude2 = magnitude(vector2);
    const cosTheta = dotProd / (magnitude1 * magnitude2);
    const theta = Math.acos(cosTheta) * (180 / Math.PI); // convert to degrees
    return theta;
}

const angleUV = angleBetweenVectors(u, v);

console.log("Sudut antara vektor u dan v (dalam derajat):", angleUV);
