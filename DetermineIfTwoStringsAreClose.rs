use std::collections::HashMap;
impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        if word1.len() != word2.len() {
        return false;
    }

    let mut mp: HashMap<char, i32> = HashMap::new();
    let mut mp1: HashMap<char, i32> = HashMap::new();

    for ch in word1.chars() {
        *mp.entry(ch).or_insert(0) += 1;
    }

    for ch in word2.chars() {
        *mp1.entry(ch).or_insert(0) += 1;
    }

    if mp == mp1 {
        return true;
    }

    for (key, value) in &mp {
        if mp1.get(key).unwrap_or(&0) == &0 {
            return false;
        }
    }

    let mut vec: Vec<i32> = mp.values().cloned().collect();
    let mut vec1: Vec<i32> = mp1.values().cloned().collect();

    vec.sort();
    vec1.sort();
    vec == vec1
    }
}
