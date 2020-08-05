const { Client, logger } = require('camunda-external-task-client-js');
const open = require('open');

// configuration for the Client:
//  - 'baseUrl': url al motor de procesos
//  - 'logger': utilidad para registrar automáticamente eventos importantes
//  - 'asyncResponseTimeout': tiempo de espera de sondeo prolongado (se emitirá una nueva solicitud)
const config = { baseUrl: 'http://localhost:8080/engine-rest', use: logger, asyncResponseTimeout: 10000 };

// crear una instancia de Cliente con configuración personalizada
const client = new Client(config);

// suscribirse al tema: 'tarjeta de crédito'
client.subscribe('charge-card', async function({ task, taskService }) {
  // Pon tu lógica de negocios aquí


  // Obtenga una variable de proceso

  const amount = task.variables.get('amount');
  const item = task.variables.get('item');

  console.log(`Charging credit card with an amount of ${amount}€ for the item '${item}'...`);

  open('https://docs.camunda.org/get-started/quick-start/success');

  // Complete the task
  await taskService.complete(task);
});