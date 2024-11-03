function vectorComponentsAndMagnitude(P1, P2) {
  // Komponen vektor
  const x = P2[0] - P1[0];
  const y = P2[1] - P1[1];
  const z = P2[2] - P1[2];
  const components = [x, y, z];

  // Besar vektor
  const magnitude = Math.sqrt(x ** 2 + y ** 2 + z ** 2);

  return {
    components,
    magnitude,
  };
}

// Titik awal dan akhir
const P1 = [6, 5, 8];
const P2 = [8, -7, 3];

const result1 = vectorComponentsAndMagnitude(P1, P2);
console.log("Komponen vektor:", result1.components);
console.log("Besar vektor:", result1.magnitude);
