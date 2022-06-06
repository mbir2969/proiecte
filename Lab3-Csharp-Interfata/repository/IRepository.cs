using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3.repository
{
    public interface Repository<Tid, T>
    {
        void add(T elem);
        void delete(Tid id);
        void update(T elem, Tid id);
        T findById(Tid id);
        IEnumerable<T> findAll();
        Collection<T> getAll();
    }
}
