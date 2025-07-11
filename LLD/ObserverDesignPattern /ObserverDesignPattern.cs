using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MyConsoleApp
{
    public interface ISuscriber{
        void Notify(string v);
    }

    public class Suscriber : ISuscriber
    {
        private string name;

        public Suscriber(string name)
        {
            this.name = name;
        }
        public void Notify(string v)
        {
            Console.WriteLine("aa gya video " + name);
        }
    }


    public class ObserverDesignPattern
    {
        public List<ISuscriber> suscribers = new List<ISuscriber>();
        public void Subscribe(ISuscriber suscriber) => suscribers.Add(suscriber);
        public void UnSubscribe(ISuscriber suscriber) => suscribers.Remove(suscriber);
         
        public void Notify(string video)
        {
            foreach (var obs in suscribers)
                obs.Notify("New video uploaded: " + video);
        }
        

    }
}



// var channel = new ObserverDesignPattern();

// var user1 = new Suscriber("Ravi");
// var user2 = new Suscriber("Rakesh");

// channel.Subscribe(user1);
// channel.Subscribe(user2);

// channel.Notify("Observer Pattern in C#");
