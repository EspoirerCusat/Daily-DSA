// See https://aka.ms/new-console-template for more information
using MyConsoleApp;

Console.WriteLine("Hello, World!");

PaypalPaymentGateway paypalPaymentGateway = new PayPalAdapter(new PaypalPaymentGateway());
paypalPaymentGateway.sendMoney("ravin", "rakesh", "1000");



