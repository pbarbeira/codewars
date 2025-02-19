/*
 * Complete the function that accepts a string parameter, and reverses each 
 * word in the string. All spaces in the string should be retained.
 *
 * Examples
 * - "This is an example!" ==> "sihT si na !elpmaxe"
 * - "double  spaces"      ==> "elbuod  secaps"
 */

function reverseWords(str) {
    var words = str.split(' ');
    var reversedWords = [];
    words.forEach(word => {
        reversedWords.push(word.split('').reverse().join(''));
    });
    return reversedWords.join(' ');
 }

const input = process.argv[2];
console.log(reverseWords(input));
