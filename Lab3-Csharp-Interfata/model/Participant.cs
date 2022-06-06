using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3.model
{
    public class Participant : Identifiable<int>
    {
        private int id;
        private string nume;
        private CategorieVarsta varsta;
        private int numarProbe;

        public Participant(string nume, CategorieVarsta varsta, int numarProbe)
        {
            this.nume = nume;
            this.varsta = varsta;
            this.numarProbe = numarProbe;
        }

        public int getID()
        {
            return id;
        }

        public string getNume()
        {
            return nume;    
        }

        public CategorieVarsta getVarsta()
        {
            return varsta;
        }

        public int getNumarProbe()
        {
            return numarProbe;  
        }
        

        public void setID(int id)
        {
            this.id = id;
        }


        public void setNume(string numeNou)
        {
            this.nume = numeNou;
        }

        public void setVarsta(CategorieVarsta varstaNoua)
        {
            this.varsta = varstaNoua;
        }

        public void setNumarProbe(int numarProbeNou)
        {
            this.numarProbe = numarProbeNou;
        }

        protected bool Equals(Participant other)
        {
            return id == other.id && nume == other.nume && varsta == other.varsta && numarProbe == other.numarProbe;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj)) return false;
            if (ReferenceEquals(this, obj)) return true;
            if (obj.GetType() != this.GetType()) return false;
            return Equals((Participant) obj);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                var hashCode = id;
                hashCode = (hashCode * 397) ^ (nume != null ? nume.GetHashCode() : 0);
                hashCode = (hashCode * 397) ^ (int) varsta;
                hashCode = (hashCode * 397) ^ numarProbe;
                return hashCode;
            }
        }


        public string ToString()
        {
            return "Participant{" +
                   "nume='" + nume + '\'' +
                   ", varsta=" + varsta +
                   ", numarProbe=" + numarProbe +
                   '}';;
        }
    }
}
