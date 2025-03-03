/*The main idea is to count all the occurring characters in a string. If you 
 * have a string like aba, then the result should be {'a': 2, 'b': 1}.
 *
 * What if the string is empty? Then the result should be empty object literal, 
 * {}.
 */

function count(string){
    const obj = {};
    for(var i = 0; i < string.length; i++){
        if(obj[string[i]] == undefined){
            obj[string[i]] = 1;
        }else{
            obj[string[i]]++;
        }
    }
    return obj;
}

const input = process.argv[2];
console.log(count(input));
