// const { json } = require("body-parser");

var formulario = document.getElementById('formulario')

formulario.addEventListener('submit', function(e){
    e.preventDefault();

    var datos = new FormData(formulario);

    var amount = datos.get('amount')
    var item = datos.get('item')

    console.log(amount)
    console.log(item)

    // var formData = JSON.stringify($("#formulario").serializeArray());

    // var json = {
    //     "variables": {
    //         "amount": {
    //             "value": amount,
    //             "type":"long"
    //         },
    //         "item": {
    //             "value": item
    //         }
    //     }
    // }

    // let xhr = new XMLHttpRequest(); 
    // let url = "http://localhost:8080/engine-rest/process-definition/key/payment-retrieval/start"; 
    
    // xhr.open("POST", url); 
    // xhr.setRequestHeader("Content-Type", "application/json"); 
    
    // // Create a state change callback 
    // // xhr.onreadystatechange = function () { 
    // //     if (xhr.readyState === 4 && xhr.status === 200) { 

    // //         // Print received data from server 
    // //         result.innerHTML = this.responseText; 

    // //     } 
    // // }; 

    // // Converting JSON data to string 
    // // var data = JSON.stringify({ "amount": amount, "item": item }); 

    // // Sending data with the request 
    
    // xhr.send(formData); 

    axios({
        url: 'http://tudireccion.com',
        method: 'post',
        headers: {'Content-type': 'text/html; charset=UTF-8'},
        data: text
    }).then(OkCallback, ErrorCallback)

    
});


// function sendJSON(){ 
               
//             let result = document.querySelector('.result'); 
//             let name = document.querySelector('#name'); 
//             let email = document.querySelector('#email'); 
               
//             // Creating a XHR object 
//             let xhr = new XMLHttpRequest(); 
//             let url = "submit.php"; 
        
//             // open a connection 
//             xhr.open("POST", url, true); 
  
//             // Set the request header i.e. which type of content you are sending 
//             xhr.setRequestHeader("Content-Type", "application/json"); 
  
//             // Create a state change callback 
//             xhr.onreadystatechange = function () { 
//                 if (xhr.readyState === 4 && xhr.status === 200) { 
  
//                     // Print received data from server 
//                     result.innerHTML = this.responseText; 
  
//                 } 
//             }; 
  
//             // Converting JSON data to string 
//             var data = JSON.stringify({ "name": name.value, "email": email.value }); 
  
//             // Sending data with the request 
//             xhr.send(data); 
//         } 