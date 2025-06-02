def validate_plate(plate):
    state = {0}  
    plate = plate.strip()
    num_digits = 0
    num_end_letters = 0
    
    for char in plate:
        next_state = set()
        for s in state:
            if s == 0:
                if char.isalpha() and char.isupper():
                    next_state.add(1)
            elif s == 1:
                if char.isalpha() and char.isupper():
                    next_state.add(1)  
                    next_state.add(2)
                if char == ' ':
                    next_state.add(2)
                next_state.add(2)
            elif s == 2:
                if char == ' ':
                    next_state.add(3)
            elif s == 3:
                if char.isdigit():
                    num_digits += 1
                    next_state.add(4)
            elif s == 4:
                if char.isdigit() and num_digits < 4:
                    num_digits += 1
                    next_state.add(4)
                    next_state.add(5)
                if char == ' ' and num_digits >= 1:
                    next_state.add(5)
                if num_digits >= 1:
                    next_state.add(5)
            elif s == 5:
                if char.isalpha() and char.isupper() and num_end_letters < 3:
                    num_end_letters += 1
                    next_state.add(5)
        
        state = next_state
        if not state:
            return False
    
    return 5 in state and 5 <= len(plate) <= 11 and num_digits >= 1 and num_end_letters >= 1

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
