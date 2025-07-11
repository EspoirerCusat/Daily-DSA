using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Threading.Tasks;

namespace MyConsoleApp
{
    public class PayPalAdapter : PaypalPaymentGateway
    {
        private PaypalPaymentGateway paypalPaymentGateway;
        public PayPalAdapter(PaypalPaymentGateway paypalPaymentGateway)
        {
            this.paypalPaymentGateway = paypalPaymentGateway;
        }

        public  void sendMoney(string from, string to, string amount)
        {
            Console.WriteLine("Making payment to :  " + to + " from : " + from + " amount : " + amount);
            paypalPaymentGateway.sendMoney(to, from, amount);
        }

    }
}
