function midpoint(P, Q) {
  const x = (P[0] + Q[0]) / 2;
  const y = (P[1] + Q[1]) / 2;
  const z = (P[2] + Q[2]) / 2;

  return [x, y, z];
}

const P = [2, 3, -2];
const Q = [7, -4, 1];

const result3 = midpoint(P, Q);
console.log("Titik tengah:", result3);
