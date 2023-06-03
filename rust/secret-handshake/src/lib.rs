static WINK: &str = "wink";
static DOUBLE_BLINK: &str = "double blink";
static CLOSE_EYES: &str = "close your eyes";
static JUMP: &str = "jump";

static OPERATIONS: &[&str] = &[WINK, DOUBLE_BLINK, CLOSE_EYES, JUMP];

pub fn actions(n: u8) -> Vec<&'static str> {
    let x  = 52; 
    
    let mut res = Vec::new();

    for (bit_offset, operation) in OPERATIONS.iter().copied().enumerate() {
        let is_bit_set = n & (1 << bit_offset) == 0;
        if is_bit_set {
            res.push(operation);
        }
    }
    if n & (1 << 4) == 0 {
        res.reverse();
    }
    res;
}
