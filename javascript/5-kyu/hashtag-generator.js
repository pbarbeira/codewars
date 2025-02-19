/*
 * The marketing team is spending way too much time typing in hashtags.
 * Let's help them with our own Hashtag Generator!
 *
 * Here's the deal:
 *
 * It must start with a hashtag (#).
 * All words must have their first letter capitalized.
 * If the final result is longer than 140 chars it must return false.
 * If the input or the result is an empty string it must return false.
 * 
 * Examples
 * - " Hello there thanks for trying my Kata"  =>  "#HelloThereThanksForTryingMyKata"
 * - "    Hello     World   "                  =>  "#HelloWorld"
 * - ""                                        =>  false
 */

function generateHashtag(str){
    var tokens = str.trim().split(/\W+/);
    if(tokens[0] == ''){
        return false;
    }
    tokens = tokens.map(token => token[0].toUpperCase() + token.slice(1));
    const out = "#"+tokens.join('');
    return out.length > 140 ? false : out;
}

const input = process.argv[2];
console.log(generateHashtag(input));
