def validate_plate(plate):
    state = 0
    plate = plate.strip()
    num_digits = 0
    num_end_letters = 0
    
    for char in plate:
        if state == 0:
            if char.isalpha() and char.isupper():
                state = 1
            else:
                return False
        elif state == 1:
            if char.isalpha() and char.isupper():
                state = 2
            elif char == ' ':
                state = 3
            else:
                return False
        elif state == 2:
            if char == ' ':
                state = 3
            else:
                return False
        elif state == 3:
            if char.isdigit():
                num_digits += 1
                state = 4
            else:
                return False
        elif state == 4:
            if char.isdigit() and num_digits < 4:
                num_digits += 1
                state = 4
            elif char == ' ' and num_digits >= 1:
                state = 5
            else:
                return False
        elif state == 5:
            if char.isalpha() and char.isupper():
                num_end_letters += 1
                state = 6
            else:
                return False
        elif state == 6:
            if char.isalpha() and char.isupper() and num_end_letters < 3:
                num_end_letters += 1
                state = 6
            else:
                return False
    
    return state == 6 and 5 <= len(plate) <= 10 and num_digits >= 1 and num_end_letters >= 1

def main():
    while True:
        plate = input("Masukkan plat (contoh: B 1234 ABC atau AB 12 CD, ketik 'exit' untuk keluar): ")
        if plate.lower() == 'exit':
            break
        if validate_plate(plate):
            print("=> Valid ✅")
        else:
            print("=> Tidak valid ❌")

if __name__ == "__main__":
    main()
