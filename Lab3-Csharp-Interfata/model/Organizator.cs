using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3.model
{
    public class Organizator : Identifiable<int>
    {
        private int id;
        private String userName;
        private String password;

        public Organizator(String userName, String password)
        {
            this.userName = userName;
            this.password = password;
        }
        public int getID()
        {
            return id;
        }

        public String getUserName()
        {
            return userName;
        }

        public String getPassword()
        {
            return password;
        }
        public void setID(int id)
        {
            this.id = id;
        }

        public void setUserName(String userName)
        {
            this.userName = userName;
        }

        public void setPassword(String password)
        {
            this.password = password;
        }

        protected bool Equals(Organizator other)
        {
            return id == other.id && userName == other.userName && password == other.password;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj)) return false;
            if (ReferenceEquals(this, obj)) return true;
            if (obj.GetType() != this.GetType()) return false;
            return Equals((Organizator) obj);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                var hashCode = id;
                hashCode = (hashCode * 397) ^ (userName != null ? userName.GetHashCode() : 0);
                hashCode = (hashCode * 397) ^ (password != null ? password.GetHashCode() : 0);
                return hashCode;
            }
        }

        public  string ToString()
        {
            return "Organizator{" +
                   "userName='" + userName + '\'' +
                   ", password='" + password + '\'' +
                   '}';
        }
    }
}
