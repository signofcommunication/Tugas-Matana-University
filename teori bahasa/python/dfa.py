def validate_plate(plate):
    plate = plate.strip()

    for c in plate:
        if c.isdigit():
            if c == '0':
                return False
            break

    states = {(0, 0, 0, 0)}

    for char in plate:
        next_states = set()
        for s, initial_letters, digits, end_letters in states:
            if s == 0:
                if char.isalpha() and char.isupper():
                    next_states.add((1, initial_letters + 1, digits, end_letters))
                elif char in ['★', '-']:
                    next_states.add((6, initial_letters, digits, end_letters))
            elif s == 1:
                if char.isalpha() and char.isupper() and initial_letters < 3:
                    next_states.add((1, initial_letters + 1, digits, end_letters))
                elif char == ' ' or char == '-':
                    next_states.add((2, initial_letters, digits, end_letters))
            elif s == 2:
                if char == ' ' or char == '-':
                    next_states.add((3, initial_letters, digits, end_letters))
                elif char.isdigit():
                    next_states.add((4, initial_letters, digits + 1, end_letters))
            elif s == 3:
                if char.isdigit():
                    next_states.add((4, initial_letters, digits + 1, end_letters))
            elif s == 4:
                if char.isdigit() and digits < 4:
                    next_states.add((4, initial_letters, digits + 1, end_letters))
                elif char == ' ' or char == '-':
                    next_states.add((5, initial_letters, digits, end_letters))
            elif s == 5:
                if char.isalpha() and char.isupper() and end_letters < 3:
                    next_states.add((5, initial_letters, digits, end_letters + 1))
                elif char == '0' and end_letters == 0:
                    next_states.add((5, initial_letters, digits, end_letters))
            elif s == 6:
                if char.isdigit():
                    next_states.add((6, initial_letters, digits + 1, end_letters))
                elif char == ' ':
                    next_states.add((4, initial_letters, digits, end_letters))
        states = next_states
        if not states:
            return False

    for s, initial_letters, digits, end_letters in states:
        if (s in {5, 6}
            and 2 <= len(plate) <= 11
            and digits >= 1
            and (initial_letters >= 1 or s == 6)):
            return True
    return False

def main():
    while True:
        plate = input("Masukkan plat (contoh: B 1234 ABC, ketik 'exit' untuk keluar): ")
        if plate.lower() == 'exit':
            break
        if validate_plate(plate):
            print("=> Valid ✅")
        else:
            print("=> Tidak valid ❌")

if __name__ == "__main__":
    main()
